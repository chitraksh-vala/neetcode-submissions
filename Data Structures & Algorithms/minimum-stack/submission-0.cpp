class MinStack {
public:
    stack<int> pranshul;
        stack<int> min;
    MinStack() {
    
        
    }
    
    void push(int val) 
    {
     pranshul.push(val); 
     if((min.empty())||(val<=min.top()))
     {
        min.push(val);
     }
       
    }
    
    void pop() {
        if (pranshul.top() == min.top())
    min.pop();

    pranshul.pop();

        
    }
    
    int top() {
        int top = pranshul.top();
        return top;
    }
    
    int getMin() 
    {
        return min.top();
    }
};
