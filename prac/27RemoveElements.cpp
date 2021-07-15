#include<iostream>
#include<vector>


    int removeElement(std::vector<int>& nums, int val) {
        int j = nums.size()-1, i =0;
        
        if(nums.size() == 0 or (nums.size() == 1 and nums[0] == val))
        {
            return 0;
        }
        
        if(nums.size() == 1 and nums[0] != val) 
        {
            return 1;
        }
        
        while(j>=0)
        {
            if(nums[j] != val)
            {
                break;
            }

            j--;
        }
        
        while(i<j)
        {
            if(nums[j] == val) j--;
            if(nums[i] == val)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
            i++;
        }
        
        return (i==j and nums[j]!=val) ? i+1 : i;
    }

int main () 
{
    std::vector<int>vec{
        3   
    };

    int idx = removeElement(vec, 3);

    for(int i=0; i<idx; i++)
    {
        std::cout << vec[i] << " " ;
    }
    std::cout << "\n" ;
    
    return 0;
}    
