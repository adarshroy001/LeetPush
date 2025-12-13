1class MyStack {
2    queue<int> q1 , q2 ; 
3public:
4    MyStack() {
5        
6    }
7    
8    void push(int x) {
9        q1.push(x) ; 
10    }
11    
12    int pop() {
13        if(!q1.empty()){
14            int size = q1.size() ; 
15            for(int i = 1 ; i < size ; ++i){
16                q2.push(q1.front()) ; q1.pop() ;
17            }
18            int ans = q1.front() ; 
19            q1.pop() ;
20            return ans ; 
21        }else{
22            int size = q2.size() ; 
23            for(int i = 1 ; i < size ; ++i){
24                q1.push(q2.front()) ; q2.pop() ;
25            }
26            int ans = q2.front() ; 
27            q2.pop() ;
28            return ans ;
29        }
30
31    }
32    
33    int top() {
34        if(!q1.empty()){
35            int size = q1.size() ; 
36            for(int i = 1 ; i < size ; ++i){
37                q2.push(q1.front()) ; q1.pop() ;
38            }
39            int ans = q1.front() ; 
40            q2.push(ans) ; q1.pop() ;
41            return ans ; 
42        }else{
43            int size = q2.size() ; 
44            for(int i = 1 ; i < size ; ++i){
45                q1.push(q2.front()) ; q2.pop() ;
46            }
47            int ans = q2.front() ; 
48            q1.push(ans) ; q2.pop() ;
49            return ans ;
50        }
51
52    }
53    
54    bool empty() {
55        if(q1.empty() && q2.empty()) return true ; 
56        return false ;
57    }
58};
59
60/**
61 * Your MyStack object will be instantiated and called as such:
62 * MyStack* obj = new MyStack();
63 * obj->push(x);
64 * int param_2 = obj->pop();
65 * int param_3 = obj->top();
66 * bool param_4 = obj->empty();
67 */