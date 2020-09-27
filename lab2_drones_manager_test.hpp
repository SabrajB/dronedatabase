#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
    bool test1() {
        DronesManager manager1;
        if(manager1.get_size() == 0 && manager1.empty() == true && manager1.first == NULL && manager1.last == NULL)
            return true;
        else
            return false;

    }

	// PURPOSE: insert_front() and insert_back() on zero-element list
    bool test2() {
           DronesManager manager1, manager2;
           manager1.insert_front(DronesManager::DroneRecord(53));
           manager2.insert_back(DronesManager::DroneRecord(93));

           if(manager1.get_size() == 1 && manager1.get_size() == manager2.get_size() && manager1.first != NULL && manager1.first == manager1.last && manager2.first != NULL && manager2.first == manager2.last && manager1.first->prev == NULL && manager1.last->next == NULL && manager2.first->prev == NULL && manager2.last->next == NULL && manager1.select(0) == DronesManager::DroneRecord(53) && manager2.select(0) == DronesManager::DroneRecord(93)) {
                   return true;
           }
           else {
                   return false;
           }
       }

	// TODO: Implement all of the test cases below

	// PURPOSE: select() and search() work properly
	bool test3() {
        DronesManager manager1;

        const int elements = 5;
        for (unsigned int index = 0; index < elements; index++)
        {
            ASSERT_TRUE(manager1.insert_back(index*10))
        }

        unsigned int test_index1 = 3;
        unsigned int test_index2 = 2;
        unsigned int test_index3 = 7;

        ASSERT_TRUE(manager1.select(test_index1) == DronesManager::DroneRecord(30))
        ASSERT_TRUE(manager1.select(10) == DronesManager::DroneRecord(40))
        ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(20)) == test_index2)
        ASSERT_TRUE(manager1.select(test_index3) == DronesManager::DroneRecord(40))
        ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(80)) == 5)

        for (unsigned int counter = 0; counter < elements; counter++)
        {
            ASSERT_TRUE(manager1.select(counter) == DronesManager::DroneRecord(counter*10))
            ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(counter*10)) == counter)
        }
        ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
        return true;

	}

	// PURPOSE: remove_front() and remove_back() on one-element list
    bool test4() {
           DronesManager manager1, manager2;

           ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(543)));
           ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(69)));

           ASSERT_TRUE(manager1.remove_front());
           ASSERT_TRUE(manager2.remove_back());

           ASSERT_TRUE(manager1.get_size() == 0)
           ASSERT_TRUE(manager2.get_size() == 0)
           ASSERT_TRUE(manager1.get_size() == manager2.get_size())
           ASSERT_TRUE(manager1.first == NULL)
           ASSERT_TRUE(manager2.get_size() == 0)
           ASSERT_TRUE(manager2.get_size() == manager1.get_size())
           ASSERT_TRUE(manager2.first == NULL)
           return true;
       }

	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
        DronesManager manager1;

        const int elements = 10;
        for (unsigned int index = 0; index < elements; index++)
        {
            ASSERT_TRUE(manager1.insert_back(index*10))
        }

        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(0))
        ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(10))
        ASSERT_TRUE(manager1.replace(0, DronesManager::DroneRecord(17)))
        ASSERT_TRUE(manager1.replace(2, DronesManager::DroneRecord(21)))
        ASSERT_TRUE(manager1.replace(6, DronesManager::DroneRecord(11)))
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(17))

        int test_array[10] = {90, 80, 70, 11, 50, 40, 30, 21, 10, 17};
        ASSERT_TRUE(manager1.reverse_list())
        for (unsigned int index = 0; index < 10; index++)
        {
            ASSERT_TRUE(manager1.select(index) == DronesManager::DroneRecord(test_array[index]))
        }

        ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)

        return true;
    }

	// PURPOSE: insert_front() keeps moving elements forward
    bool test6() {
        DronesManager manager1, manager2;

        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(54)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(43)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(53)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(35)));

        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(34)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(42)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(981)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(3)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(5432)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(4323222)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(5)));
        ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(43)));

        ASSERT_TRUE(manager1.get_size() == 4);
        ASSERT_TRUE(manager2.get_size() == 8);
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(35))
        ASSERT_TRUE(manager2.select(0) == DronesManager::DroneRecord(43))
        ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(53))
        ASSERT_TRUE(manager2.select(1) == DronesManager::DroneRecord(5))
        ASSERT_TRUE(manager1.select(3) == DronesManager::DroneRecord(54))
        ASSERT_TRUE(manager2.select(7) == DronesManager::DroneRecord(34))
        ASSERT_TRUE(manager1.select(2) == DronesManager::DroneRecord(43))
        return true;
    }

	// PURPOSE: inserting at different positions in the list
	bool test7() {
            DronesManager manager1;

            const int elements = 10;
            for (unsigned int index = 0; index < elements; index++)
            {
                ASSERT_TRUE(manager1.insert_back(index*10))
            }
            ASSERT_TRUE(manager1.get_size() == 10)
            ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(75), 10))

            ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(15), 1))
            ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(93), 2))
            ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(71), 5))
            ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(8), 11))

            int test_array[] = {0, 15, 93, 10, 75, 71, 20, 8, 30, 40, 50, 60, 70, 80, 90};
            ASSERT_TRUE(manager1.get_size() == 15)

            for (unsigned int i = 0; i < 1 ; i++) {
                ASSERT_TRUE(manager1.select(i) == DronesManager::DroneRecord(test_array[i]))
            }
            ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)

        return true;
	}

	// PURPOSE: try to remove too many elements, then add a few elements
    bool test8() {
        DronesManager manager1;

        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(100)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(24)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(12)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(690)));
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(167)));

        ASSERT_TRUE(manager1.size == 5);
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.size == 2);
        ASSERT_TRUE(manager1.remove(1));
        ASSERT_TRUE(manager1.size == 1);
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_FALSE(manager1.remove_front());
        ASSERT_FALSE(manager1.remove_back());
        ASSERT_TRUE(manager1.size == 0);
        ASSERT_FALSE(manager1.remove(3));
        ASSERT_FALSE(manager1.remove_front());

        ASSERT_TRUE(manager1.get_size() == 0)

        manager1.insert_front(DronesManager::DroneRecord(42));
        manager1.insert_front(DronesManager::DroneRecord(13));
        manager1.insert_front(DronesManager::DroneRecord(146));

        ASSERT_TRUE(manager1.get_size() == 3)
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(146))
        ASSERT_TRUE(manager1.select(2) == DronesManager::DroneRecord(42))

        return true;
    }

	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
        DronesManager manager1;
        ASSERT_FALSE(manager1.remove(0))
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(1)))
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(0)))
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(31)))
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(14)))
        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(59)))
        ASSERT_FALSE(manager1.insert(DronesManager::DroneRecord(59), 6))
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(12)))
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(51)))
        ASSERT_FALSE(manager1.insert(DronesManager::DroneRecord(12),9))
        ASSERT_TRUE(manager1.get_size() == 7)
        ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(18), 6));
        ASSERT_TRUE(manager1.remove_back())
        ASSERT_FALSE(manager1.remove(12))
        ASSERT_TRUE(manager1.remove_front())
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(88)))

        int test_array[] = {14, 31, 0, 1, 12, 18, 88};
                   ASSERT_TRUE(manager1.get_size() == 7)

                   for (unsigned int i = 0; i < 7; i++) {
                       ASSERT_TRUE(manager1.select(i) == DronesManager::DroneRecord(test_array[i]))
                   }

        ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)

        return true;
	}

	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
    bool test10() {
        DronesManager manager1;

        ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(132)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(2)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(122)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(437)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(123)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(1)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(24)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(42)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(637)));
        ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(19)));

        ASSERT_TRUE(manager1.reverse_list());

        ASSERT_TRUE(manager1.get_size() == 10)
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(19))
        ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(637))
        ASSERT_TRUE(manager1.first->prev == NULL)
        ASSERT_TRUE(manager1.select(9) == DronesManager::DroneRecord(132))
        ASSERT_TRUE(manager1.select(8) == DronesManager::DroneRecord(2))
        ASSERT_TRUE(manager1.last->next == NULL)

        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_back());

        ASSERT_TRUE(manager1.get_size() == 5)
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(1))
        ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(123))
        ASSERT_TRUE(manager1.first->prev == NULL)
        ASSERT_TRUE(manager1.select(4) == DronesManager::DroneRecord(2))
        ASSERT_TRUE(manager1.select(3) == DronesManager::DroneRecord(122))
        ASSERT_TRUE(manager1.last->next == NULL)

        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_front());
        ASSERT_TRUE(manager1.remove_back());

        ASSERT_TRUE(manager1.get_size() == 0)
        ASSERT_TRUE(manager1.first == NULL)
        ASSERT_TRUE(manager1.last == NULL)

       return true;
    }
};

#endif
