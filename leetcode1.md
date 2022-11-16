leetcode 训练2
数组相加合并
//第一种开辟n+1长度数组的平均效率更优，因为减小了遍历长度和空间成本
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
      int x=k;
      int i=0,j=0;
      int n;
      int t=0;
      int size=0;
      while(x!=0)
      {
          x=x/10;
          i++;
      }
      if(numSize>=i)
      {
          n=numSize;
      }
      else{n=i;}
      int m=n+1;
      int *arr=(int*)malloc(sizeof(int)*m);
      for(j=m-1;j>=0;j--){
          arr[j]=0;
      }
      for(j=m-1;j>m-1-i;j--){
          arr[j]=k%10;
          k=k/10;
      }
      j=m-1;
      x=numSize-1;
      while(n>0||t==1)
      {
        size++;
           if(x>=0)
           {
               if((num[x]+arr[j]+t)>=10)
               {
                   arr[j]=(num[x]+arr[j]+t)%10;
                   t=1;
               } 
               else
               {
                   arr[j]=(num[x]+arr[j]+t)%10;
                   t=0;
               }
                   x--;
                   j--;
                   n--;
           } 
           else
           {
               if((0+arr[j]+t)>=10)
               {
                   arr[j]=(0+arr[j]+t)%10;
                   t=1;
               } 
               else
               {
                   arr[j]=(0+arr[j]+t)%10;
                   t=0;
               }
                j--;
                n--;
           }
      }
      if(arr[0]==0)
      {
          for(int y=0;y<m-1;y++)
          {
              arr[y]=arr[y+1];
          }
      }
      //到逆序部分
      *returnSize=size;
      return arr;
}



//第二种
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
      int x=k;
      int i=0,j=0;
      int n;
      int t=0;
      int size=0;
      while(x!=0)
      {
          x=x/10;
          i++;
      }
      int *arr=(int*)malloc(sizeof(int)*10001);
      for(j=10000;j>=0;j--){
          arr[j]=0;
      }
      for(j=10000;j>10000-i;j--){
          arr[j]=k%10;
          k=k/10;
      }
      if(numSize>=i)
      {
          n=numSize;
      }
      else{n=i;}
      j=10000;
      x=numSize-1;
      while(n>0||t==1)
      {
        size++;
           if(x>=0)
           {
               if((num[x]+arr[j]+t)>=10)
               {
                   arr[j]=(num[x]+arr[j]+t)%10;
                   t=1;
               } 
               else
               {
                   arr[j]=(num[x]+arr[j]+t)%10;
                   t=0;
               }
                   x--;
                   j--;
                   n--;
           } 
           else
           {
               if((0+arr[j]+t)>=10)
               {
                   arr[j]=(0+arr[j]+t)%10;
                   t=1;
               } 
               else
               {
                   arr[j]=(0+arr[j]+t)%10;
                   t=0;
               }
                j--;
                n--;
           }
      }
      int a=0;
      int b=10001-size;
      n=size;
      while(n)
      {
          arr[a]=arr[b];
          a++;
          b++;
          n--;
      }
      //到逆序部分
      *returnSize=size;
      return arr;
}






数组合并
1.创建第三个数组，将一二数组比较之后放入第三个数组中，再放回第一个数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int arr[m+n];
    int j=0,k=0;
    for(int i=0;i<m+n;i++)
    {
        if(j<m&&k<n&&nums1[j]<=nums2[k])
        {
            arr[i]=nums1[j];
            j++;
        }
        else if(j<m&&k<n&&nums1[j]>nums2[k])
        {
            arr[i]=nums2[k];
            k++;
        }
        else if(j==m&&k<n)
        {
            arr[i]=nums2[k];
            k++;
        }
        else if(k==n&&j<m)
        {
            arr[i]=nums1[j];
            j++;
        }
    }
    for(int i =0 ;i<m+n;i++)
    {
        nums1[i]=arr[i];
    }
}

优化：
int * tmp=(int*)malloc(sizeof(int)*(m+n));
int i=0,j=0;
int k=0;
while(i<m && j<n)
{
    if(nums[i]<nums[j])
     {
       tmp[k++]=nums1[i++];
     }
    else
    {
       tmp[k++]=nums2[j++];
     }
}

while(i<m)
     tmp[k++]=nums1[i++];
while(j<n）
     tmp[k++]=nums2[j++];

memcpy(nums1,tmp,sizeof(int)*(m+n));
free(tmp);
tmp=NULL;


2.直接将第二个数组充入第一个数组再排序，可节省空间和时间(可能节省时间)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int t;
//memcpy(nums1+m,nums2,sizeof(int)*n);拷贝数组2到数组1
    for(int i=m;i<m+n;i++)
    {
        nums1[i]=nums2[i-m];
    }
    for(int i =0 ;i<m+n;i++)
    {
        for(int j=0;j<m+n-i-1;j++)
        {
            if(nums1[j]>nums1[j+1])
            {
                t=nums1[j];
                nums1[j]=nums1[j+1];
                nums1[j+1]=t;
            }
        }
    }
}

数组删除重复项
1.双重for循环删除重复项，代码简单，但是效率低
int removeDuplicates(int* nums, int numsSize)
{
  for(int i=0;i<numsSize-1;i++)
  {
      if(nums[i]==nums[i+1])
      {
          for(int j=i;j<numsSize-1;j++)
          {
              nums[j]=nums[j+1];
          }
          i--;
          numsSize--;
      }
  }
  return numsSize;
}

2.双指针单次循环法，将不重复元素放到数组前项
int removeDuplicates(int* nums, int numsSize)
{
  int *p=nums;
  int *p1=&nums[1];
  int n=0;//用来记录交换次数
  int k=1;//用来结束循环，防止指针越界
  while(k<numsSize)
  {
      if((*p)!=(*p1))
      {
          *(p+1)=*p1;
          p++;
          p1++;
          n++;
          k++;
      }
      else if(*p==*p1)
      {
          p1++;
          k++;
      }
  }
  numsSize=n+1;
  return numsSize;
}

不构建新指针只使用下标的写法：
int removeDuplicates(int* nums, int numsSize)
{
  int p=0;
  int q=1;
  while(q<numsSize)
  {
      if(nums[p]!=nums[q])
      {
          nums[p+1]=nums[q];
          p++;
          q++;
      }
      else if(nums[p]==nums[q])
      {
          q++;
      }
  }
  numsSize=p+1;
  return numsSize;
}

3.双指针比较前项法
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize<=1)
    return numsSize;

    int t= 1;//第一个元素不可能是重复数据
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[t++]=nums[i];
        }
    }
    return t;
}

删除数组元素val
1.双指针删除法
int removeElement(int* nums, int numsSize, int val)
{
    int p=0;
    int q=0;
    while(q<numsSize)
    {
        if(nums[p]==val)
        {
            if(nums[q]==val)
            {
                q++;
            }
            else if(nums[q]!=val)
            {
                nums[p]=nums[q];
                nums[q]=val;
                p++;
                q++;
            }
        }
        else if(nums[p]!=val)
        {
            p++;
            q++;
        }
    }
    return p;
}

2.双重for循环法
int removeElement(int* nums, int numsSize, int val)
{
  for(int i=0;i<numsSize;i++)
  {
      if(nums[i]==val)
      {
        for(int j=i;j<numsSize-1;j++)
          {
              nums[j]=nums[j+1];
          }
          if(nums[i]==val)
          {
              i=i-1;//哪怕i初始值为0也不影响，当i变为-1结束这次循环后也会+1变为0，又从零开始判断循环，也可以把i++的循环条件放到下面来
              numsSize--;
          }
          else
          {
              numsSize--;
          }
      }
  }
  return numsSize;
}

3.尾指针与对应指针交换法，但是会改变元素顺序