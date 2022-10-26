消失的数字--c语言
解法一：求差法
int missingNumber(int* nums, int numsSize){
    int val=numsSize;
    for(int i=0;i<numsSize;i++){
        val=i-nums[i]+val;
    }
    return val;
}
解法二：异或法
int missingNumber(int* nums, int numsSize){
    int val=numsSize;
    for(int i=0;i<numsSize;i++){
        val^=i^nums[i] ;   //所有成对的数异或之后为0，而剩下的单个数被留下来赋给val
        }
    return val;
}
如1，0 ，3 与0，1，2，3异或哪怕无序，1和1，0和0，3和3总会因为异或变为0，从而只剩下2

旋转数组--c语言
解法一：额外数组 思路：将旋转后元素通过取余法按对应位置放在新数组中再放回原数组
void rotate(int* nums, int numsSize, int k){
    int arr[numsSize];
    k = k % numsSize; //减少旋转次数减少运行时间
    for(int i=0;i<numsSize;i++){
        arr[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        nums[i]=arr[i];
    }
}
2：思路：通过交换函数可以不依靠新的数组进行旋转，前n-k个元素逆置保证在整体逆转时，前n-k个元素先后次序不变，
而后k个元素逆置也同样保证整体逆置时后k个元素的先后次序不变，从而可以把这两部分看作两个切割后的单独数组，整体
逆置即使两个数组顺序的调换。  
void swap(int* a,int* b)//反转
{
    int p=*a;
    *a=*b;
    *b=p;
}
void revers(int* nums,int up,int down)//重复进行反转  直到完成
{
    while(up<down)
    {
        swap(&nums[up],&nums[down]);//初始位与末尾位进行反转  直到进行到中间位置
        up++;
        down--;        
    }
}

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    revers(nums,0,numsSize-1);//整体反转
    revers(nums,0,k-1);//左侧绕着中间反转
    revers(nums,k,numsSize-1);//右侧绕着中间反转
    return nums;    
}
