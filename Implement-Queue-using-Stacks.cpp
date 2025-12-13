1class MyQueue {
2    stack<int> s1, s2 ; 
3public:
4    MyQueue() {
5
6    }
7    
8    void push(int x) {
9        s1.push(x) ; 
10    }
11    
12    int pop() {
13        if(s2.empty()){
14            while(!s1.empty()){
15                s2.push(s1.top()) ; s1.pop() ; 
16            }
17        }
18        int val  = s2.top() ; 
19        s2.pop() ;
20        return val ; 
21    }
22    
23    int peek() {
24        if(s2.empty()){
25            while(!s1.empty()){
26                s2.push(s1.top()) ; s1.pop() ; 
27            }
28        }
29        return s2.top() ; 
30    }
31    
32    bool empty() {  
33        if(s1.empty() && s2.empty()) return true ; 
34        return false ;
35    }
36};
37
38/**
39 * Your MyQueue object will be instantiated and called as such:
40 * MyQueue* obj = new MyQueue();
41 * obj->push(x);
42 * int param_2 = obj->pop();
43 * int param_3 = obj->peek();
44 * bool param_4 = obj->empty();
45 */