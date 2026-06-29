class Solution {
public:
    int trap(vector<int>& height) 
    {
        int size =height.size();
        int output=0;
        int c=0;
        for(int i=0;i<size-1;i++)
        {   int temp = 0;
            int a=i;
            int b=a+1;
            int a_height=height[a];
            if(a!=c)
            {   
                continue;
            }
            while(b<size)
            {   
                if(a_height==0)
                {   c++;
                    break;
                }
                else if(a_height>height[b])
                {   if(b==size-1)
                    {
                        b=a+1;
                        temp=0;
                        a_height--;
                    }
                    else
                    {
                        temp += a_height-height[b];
                        b++;
                    }
                }
                else if(a_height<=height[b])
                {   output += temp;
                    c=b;
                    b++;
                    break;
                }

            }
        
        }
        return output;
    }
};