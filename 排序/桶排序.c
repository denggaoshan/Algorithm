void bucket_sort(unsigned * arr,int len)
{
unsigned *buckets[10];//ָ������
unsigned n=1;//����ȡ������λ�ϵ�ֵ
int index;//�����±��������
int indexs[10];//����Ͱ�±��������
int i,j;

//���䶯̬�ڴ���ΪͰ
for(i=0;i<10;++i)
buckets[i]=(unsigned *)malloc(sizeof(unsigned)*len);

while(1)
{
//������������
index=0;
for(i=0;i<10;++i)
indexs[i]=0;

//������Ͱ
for(i=0;i<len;++i)
buckets[arr[i]/n%10][indexs[arr[i]/n%10]++]=arr[i];

//Ͱ������
for(i=0;i<10;++i)
for(j=0;j<indexs[i];++j)
arr[index++]=buckets[i][j];

//ΪȡԪ�ص���һλ��׼��
n*=10;

//�ж��Ƿ�ý���
for(i=0;arr[i]<n&&i<len;++i);
if(i==len) break;
}

//�ͷŶ�̬�ڴ�
for(i=0;i<10;++i)
free(buckets[i]);
}