��������λ��
int searchInsert(int* nums, int numsSize, int target)
{
  int l=0;
  int r=numsSize-1;
  while(l<=r)
  {
      //����ҪѰ�ҵ�λ����ͨ�����һ�αȽϵõ��ģ�������ͨ��ǰ�漸�αȽϵõ��ģ���������ô�۰룬���һ�αȽϵ����ұ߽綼��Ҫ�ҵ�λ�õĸ���������ͨ������l����r+1����λ��
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
//ע�⣺����һ��ʼ�ķ�ʽ�����Խ��Ƚϣ��Ӷ��õ�����𰸡�


x������ƽ����
int mySqrt(int x)
{
//����һ����0��n���������������������飬���������±������Ԫ��ֵһһ��Ӧ
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
      else if(mid*mid<x&&(mid+1)*(mid+1)<=x)//�����ж��Ƿ���Ҫ�����۰�
      {
          l=mid+1;
      }
      else if(mid*mid<x&&(mid+1)*(mid+1)>x)//�ҵ���������ӽ�����ƽ��������
      {
          break;
      }
      else if(mid*mid==x)
      {
          break;
      }
  }
  int n;//ǿ��ת��
  n=(int)mid;
  return n;
}