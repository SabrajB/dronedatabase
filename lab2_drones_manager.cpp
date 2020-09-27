#include "lab2_drones_manager.hpp"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
    first = last = NULL; // set both first and last to null
    size = 0; // initiate size to 0
}

DronesManager::~DronesManager() {
    // free up all the nodes in the list
    // [droneID = 100] -> [droneID = 200] -> [DroneID = 300] -> NULL
    DroneRecord* cur = first;
    while(cur) {
        cur = cur->next;
        first -> next = NULL;
        first -> prev = NULL;
        first = NULL;
        delete first;
        first = cur;
    }
    first = last = NULL;
    size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
    bool are_equal = true;
    if (lhs.droneID != rhs.droneID) {
        return false;
    }
    return are_equal;
}

unsigned int DronesManager::get_size() const {
    DroneRecord* cur = first;
    if (!cur)
        return 0;
    else {
        int size = 0;
        while(cur) {
            size++;
            cur = cur ->next;
        }
        return size;
    }
    
}

bool DronesManager::empty() const {
    DroneRecord* cur = first;
    if (cur == NULL)
        return true;
    else return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
    int number = index;
    DroneRecord* cur1 = first;
    DroneRecord* cur2 = last;
    if (cur1 == NULL)
        return DroneRecord(0);
    else {
        int counter = 0;
        while (cur1)
        {
             if (counter == number)
             {
                 return DroneRecord(cur1->droneID);
             }
            counter++;
            cur1 = cur1->next;
        }
        return DroneRecord(cur2->droneID);
    }
}

unsigned int DronesManager::search(DroneRecord value) const {
    int index = 0;
    DroneRecord* temp = new DroneRecord(value);
    DroneRecord* cur = first;
    if (cur == NULL)
        return 0;
    else {
        while(cur) {
            if(cur->droneID == temp->droneID)
                return index;
            else {
                index++;
                cur = cur->next;
            }
        }
        return index;
    }
}

void DronesManager::print() const {
    cout << "(";
   DroneRecord* cur = first;
   while (cur) {
       cout << "[" << cur->droneID << "]";
       cur = cur->next;
       if (cur)
           cout << "->";
   }
    cout << ")\n";
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
    DroneRecord* insertNode = new DroneRecord(value);

    
    
    if (index > size) {
        return false;
    }
    
    else if (index == size) {
        insert_back(value);
        return true;
    }
    
    else if (index == 0 || size == 0)
        return insert_front(value);
    
    else {
        DroneRecord* cur = first;
        DroneRecord* temp = first->prev;
        while (index > 0) {
            temp = cur;
            cur = cur->next;
            --index;
        }
        temp->next = insertNode;
        insertNode->next = cur;
        cur->prev = insertNode;
        insertNode->prev = temp;
        ++size;
        return true;
    }
}

bool DronesManager::insert_front(DroneRecord value) {
    DroneRecord* temp = new DroneRecord(value);
    // base case: empty list
    if (!first)
        first = last = temp;
    else {
        temp -> next = first;
        first -> prev = temp;
        temp -> prev = NULL;
        first = temp;
    }
    ++size;
    return true;
}

bool DronesManager::insert_back(DroneRecord value) {
    DroneRecord* temp = new DroneRecord(value);
    // base case: empty list
    if (!first)
        first = last = temp;
    else {
        DroneRecord* cur = first;
        while (cur -> next) {
            cur = cur -> next;
        }
        cur -> next = temp;
        temp -> prev = cur;
        temp -> next = NULL;
        last = temp;
    }
    ++size;
    return true;
}

bool DronesManager::remove(unsigned int index) {
    
    if (index < 0 || index >= size)
        return false;
        
    else if (index == 0 || size == 0) {
        remove_front();
        return true;
    }
    
    else if (index == size-1) {
        remove_back();
        return true;
    }
    
    else {
        int counter = 0;
        DroneRecord* cur = first;
        DroneRecord* temp = NULL;
        while (counter != index && cur->next)
        {
            temp = cur;
            cur = cur -> next;
            counter++;
        }
        
        temp->next = cur->next;
        cur->next->prev = temp;
        cur->next = NULL;
        cur->prev = NULL;
        cur = NULL;
        delete(cur);
        --size;
        return true;
    }
}


bool DronesManager::remove_front() {
    if (!first)
        return false;
    else if (first && first -> next == NULL) {
        DroneRecord* node = first;
        delete(node);
        first = NULL;
        last = NULL;
        --size;
        return true;
    }
    else {
        DroneRecord* cur = first;
        first = cur->next;
        first -> prev = NULL;
        cur-> prev = NULL;
        cur->next = NULL;
        delete(cur);
        --size;
        return true;
    }
}

bool DronesManager::remove_back() {
    if (!first)
        return false;
    else if (first && first -> next == NULL) {
        DroneRecord* node = first;
        delete(node);
        first = NULL;
        last = NULL;
        --size;
        return true;
    }
    else {
        DroneRecord* cur = first;
        DroneRecord* temp = NULL;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        temp = cur -> prev;
        temp -> next = NULL;
        delete(cur);
        last = temp;
        --size;
        return true;
    }
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
    DroneRecord* replaceNode = new DroneRecord(value);
    DroneRecord* cur = first;
    
    int counter = 0;

    while (counter != index && cur -> next)
    {
        cur = cur -> next;
        counter++;
    }
    replaceNode -> prev = cur -> prev;
    replaceNode -> next = cur -> next;
    cur = replaceNode;
    
    if (counter == 0) {
        first = replaceNode;
        replaceNode->prev = NULL;
        cur->next->prev = replaceNode;
    }
    else if (!cur->next) {
        last = replaceNode;
        replaceNode->next = NULL;
        cur->prev->next = replaceNode;
    }
    else {
        cur->prev->next = replaceNode;
        cur->next->prev = replaceNode;
    }
    return true;
}

bool DronesManager::reverse_list() {
    DroneRecord* cur = first;
    DroneRecord* temp = NULL;
    last = cur;
    while (cur) {
        temp = cur-> prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
        first = temp->prev;
        first->prev = NULL;
    return true;
}



