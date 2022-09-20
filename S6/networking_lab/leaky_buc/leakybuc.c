#include<stdio.h>
void main()
{
	int bucket_size,outgoing_rate,no_of_inputs,packet_size,in_bucket=0,drop,i;
	printf("Enter the bucket size:");
	scanf("%d",&bucket_size);
	printf("Enter the outgoing rate:");
	scanf("%d",&outgoing_rate);
	printf("Enter the no of inputs:");
	scanf("%d",&no_of_inputs);
	for(i=0;i<no_of_inputs;i++)
	{
		printf("\nEnter the incoming packet size:");
		scanf("%d",&packet_size);
		in_bucket=in_bucket+packet_size;
		if(in_bucket>bucket_size)
		{
			drop=in_bucket-bucket_size;
			printf("Dropped %d\n",drop);
			in_bucket=bucket_size;
		}
		printf("%d present in bucket out of %d",in_bucket,bucket_size);
		in_bucket=in_bucket-outgoing_rate;
		printf("\n%d left out of %d\n",in_bucket,bucket_size);
	}
}