class MyStack{
public:
queue<int>q;

    MyStack(){

    }

    void push(int x){
        q.push(x);
        for(int i = 0; i < q.size(); i++){
            int frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
    }

    int pop(){
        int top = q.front();
        q.pop();
        return top;
    }

    int top(){
        return q.front();

    }

    bool empty(){
        return q.empty();
    }
};