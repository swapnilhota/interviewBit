stack<int>* s;
stack<int>* minStk;

MinStack::MinStack() {
    s = new stack<int>();
    minStk = new stack<int>();
}

void MinStack::push(int x) {
    s->push(x);
    if(minStk->empty())
    {
        minStk->push(x);
    }
    else
    {
        if(x<minStk->top())
        {
            minStk->push(x);
        }
    }
}

void MinStack::pop() {
    if((s->size())==0)
    {
        return;
    }
    if(minStk->top()==s->top())
    {
        minStk->pop();
    }
    s->pop();
}

int MinStack::top() {
    if(s->size()==0)
    {
        return -1;
    }
    return s->top();
}

int MinStack::getMin() {
    if(s->size()==0)
    {
        return -1;
    }
    
    return minStk->top();
}

