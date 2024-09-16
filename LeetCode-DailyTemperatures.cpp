#include "Debug.cpp"


struct Stack{
    int val;
    int index;
    Stack* next = nullptr;

    Stack(int val, int index): val(val), index (index){};
};

Stack* push(int val,int index, Stack* head){
    Stack* newHead = new Stack(val,index);
    newHead -> next = head;
    return newHead;
}

Stack* pop(Stack* head){
    Stack* newHead = head->next;
    head->next = nullptr;
    delete head;
    return newHead;
}

void deleteStack(Stack* head){
    while (head){
        Stack* temp = head;
        head = head -> next;
        delete temp;
    }
}

void print(Stack* head){
    while (head){
        cout << head -> val << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        Stack* head = new Stack(temperatures[0],0);

        for (int i = 1; i < temperatures.size(); i++){
            while (head != nullptr && temperatures[i] > head->val){
                res[head->index] = i-head->index;
                head = pop(head);
            }
            head = push(temperatures[i],i,head);
        }

        deleteStack(head);
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> inp {73,74,75,71,69,72,76,73};
    vector<int> res = solution.dailyTemperatures(inp);
}