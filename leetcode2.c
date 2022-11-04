搜索插入位置
int searchInsert(int* nums, int numsSize, int target)
{
  int l=0;
  int r=numsSize-1;
  while(l<=r)
  {
      //我们要寻找的位置是通过最后一次比较得到的，而不是通过前面几次比较得到的，而不管怎么折半，最后一次比较的左右边界都在要找的位置的附近，可以通过返回l或者r+1来定位。
      int mid=(l+r)/2;
      if(target<nums[mid])
      {
          r=mid-1;
      }
      else if(target==nums[mid])
      {
          return mid;
      }
      else
      {
          l=mid+1;
      }
  }
  return r+1;
}
//注意：用我一开始的方式会产生越界比较，从而得到错误答案。


x的算数平方根
int mySqrt(int x)
{
//想象一个由0到n个数构建的有序整型数组，它的数组下标和数组元素值一一对应
  int l=0;
  int r=x;
  double mid=0;
  while(l<=r)
  {
      mid=l+(r-l)/2;
      if(mid*mid>x)
      {
          r=mid-1;
      }
      else if(mid*mid<x&&(mid+1)*(mid+1)<=x)//用来判断是否还需要进行折半
      {
          l=mid+1;
      }
      else if(mid*mid<x&&(mid+1)*(mid+1)>x)//找到整数中最接近算术平方根的数
      {
          break;
      }
      else if(mid*mid==x)
      {
          break;
      }
  }
  int n;//强制转换
  n=(int)mid;
  return n;
}