#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& st, int num) {
    if(st.empty()) {
        st.push(num);
    } else {
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, num);
        st.push(topElement);
    }
}

void reverseStack(std::stack<int>& st) {
    if(st.empty()) return;
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

int main() {
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // when you pop, order will be 4, 3, 2, 1
    // but we want 1, 2, 3, 4 even when popping
    // so we call the reverse function
    reverseStack(st);
    while(!st.empty()) {
        std::cout << st.top();
        st.pop();
    }
    return 0;
}