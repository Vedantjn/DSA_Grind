class MyQueue{
public:
    stack<int>s1, s2;

    MyQueue(){

    }

    void push(int x){
        s1.push(x);

    }

    int pop(){
        int poppedElement = -1;
        if(!s2.empty()){
            poppedElement = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            poppedElement = s2.top();
        }
        s2.pop();
        return poppedElement;

    }
    
    int peek(){
        int frontElement = -1;
        if(!s2.empty()){
            frontElement = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            frontElement = s2.top();
        }
        return frontElement;

    }

    bool empty(){
        return s1.empty() && s2.empty();

    }

};