leetcode ѵ��2
������Ӻϲ�
//��һ�ֿ���n+1���������ƽ��Ч�ʸ��ţ���Ϊ��С�˱������ȺͿռ�ɱ�
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
      //�����򲿷�
      *returnSize=size;
      return arr;
}



//�ڶ���
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
      //�����򲿷�
      *returnSize=size;
      return arr;
}






����ϲ�
1.�������������飬��һ������Ƚ�֮���������������У��ٷŻص�һ������
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

�Ż���
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
while(j<n��
     tmp[k++]=nums2[j++];

memcpy(nums1,tmp,sizeof(int)*(m+n));
free(tmp);
tmp=NULL;


2.ֱ�ӽ��ڶ�����������һ�����������򣬿ɽ�ʡ�ռ��ʱ��(���ܽ�ʡʱ��)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int t;
//memcpy(nums1+m,nums2,sizeof(int)*n);��������2������1
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

����ɾ���ظ���
1.˫��forѭ��ɾ���ظ������򵥣�����Ч�ʵ�
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

2.˫ָ�뵥��ѭ�����������ظ�Ԫ�طŵ�����ǰ��
int removeDuplicates(int* nums, int numsSize)
{
  int *p=nums;
  int *p1=&nums[1];
  int n=0;//������¼��������
  int k=1;//��������ѭ������ָֹ��Խ��
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

��������ָ��ֻʹ���±��д����
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

3.˫ָ��Ƚ�ǰ�
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize<=1)
    return numsSize;

    int t= 1;//��һ��Ԫ�ز��������ظ�����
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[t++]=nums[i];
        }
    }
    return t;
}

ɾ������Ԫ��val
1.˫ָ��ɾ����
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

2.˫��forѭ����
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
              i=i-1;//����i��ʼֵΪ0Ҳ��Ӱ�죬��i��Ϊ-1�������ѭ����Ҳ��+1��Ϊ0���ִ��㿪ʼ�ж�ѭ����Ҳ���԰�i++��ѭ�������ŵ�������
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

3.βָ�����Ӧָ�뽻���������ǻ�ı�Ԫ��˳��