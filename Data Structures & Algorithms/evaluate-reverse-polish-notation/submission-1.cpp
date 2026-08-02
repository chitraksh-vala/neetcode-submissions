class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        int total = 0;
        stack<int> numbers;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-"&& tokens[i]!="*" && tokens[i]!="/")
            {
                numbers.push(stoi(tokens[i]));
            }
            else if(tokens[i]=="+")
            {
            int x = numbers.top();
            numbers.pop();
            int y = numbers.top();
            numbers.pop();
            total= y + x;
            numbers.push(total);
            }
            else if(tokens[i]=="-")
            {
            int x = numbers.top();
            numbers.pop();
            int y = numbers.top();
            numbers.pop();
            total= y - x;
            numbers.push(total);
            }
            else if(tokens[i]=="*")
            {
            int x = numbers.top();
            numbers.pop();
            int y = numbers.top();
            numbers.pop();
            total= y * x;
            numbers.push(total);
            }
            else if(tokens[i]=="/")
            {
            int x = numbers.top();
            numbers.pop();
            int y = numbers.top();
            numbers.pop();
            total= y / x;
            numbers.push(total);
            }
        }
        return numbers.top();
    }
};
