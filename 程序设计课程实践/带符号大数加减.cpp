#include<stdio.h>
#include<string.h>
struct bigNum {
	int num[1000];
	int len;
};
struct bigNum toBigNum(char str[]){
	struct bigNum bn;
	if (str[0]=='-'){
		bn.num[0]=-1;
		bn.len=strlen(str);
	}else{
		bn.num[0]=1;
		bn.len=strlen(str)+1;
	}
	//倒置输入 
	for(int i=1;i<bn.len;i++){
		bn.num[i]=str[strlen(str)-i]-'0';
	}
	return bn;
	
} 
void output(struct bigNum bn){
	if(bn.num[0]==1){
		for(int i=bn.len-1;i>0;i--){
			printf("%d",bn.num[i]);
		}
		printf("\n");
	}else if (bn.num[0]==-1){
		printf("-");
		for(int i=bn.len-1;i>0;i--){
			printf("%d",bn.num[i]);
		}
		printf("\n");
	}
}
struct bigNum numadd(struct bigNum bn1,struct bigNum bn2){
	struct bigNum bn;
	if(bn1.num[0]==bn2.num[0]){
		bn.num[0]=bn1.num[0];
		if(bn1.len>=bn2.len) bn.len=bn1.len;
		else bn.len=bn2.len;
		int temp=0,i=1,j=1;
		while(i<bn1.len&&j<bn2.len){
			if(bn1.num[i]+bn2.num[i]+temp>=10){
				bn.num[i]=(bn1.num[i]+bn2.num[i]+temp)%10;
				temp=1;
			}else{
				bn.num[i]=bn1.num[i]+bn2.num[i]+temp;
				temp=0;
			}
			i++;
			j++;
		} 
		//加到最后需要进位 
		if(temp!=0&&i>=bn1.len&&j>=bn2.len){
			bn.len++;
			bn.num[i]=temp;
		}
		if(i<bn1.len) bn1.num[i]+=temp;
		if(j<bn2.len) bn2.num[i]+=temp;
		while(i<bn1.len){
			bn.num[i]=bn1.num[i];
			i++;
		}
		while(j<bn2.len){
			bn.num[j]=bn2.num[j];
			j++;
		}
	}else{ //符号不等 
		if(bn1.len>bn2.len){
			bn.len=bn1.len;
			bn.num[0]=bn1.num[0];
		int temp=0,i=1,j=1;
		while(i<bn1.len&&j<bn2.len){
			if(bn1.num[i]-bn2.num[j]-temp<0){
				bn.num[i]=bn1.num[i]+10-bn2.num[i]-temp;
				temp=1;
			}else{
				bn.num[i] = bn1.num[i]-bn2.num[i]-temp;
				temp=0;
			}
			i++;
			j++;
		}
		if(i<bn1.num[i]) bn1.num[i] = bn1.num[i]-temp;
		if(j<bn2.num[i]) bn2.num[j] = bn2.num[j]-temp;
		while(i < bn1.len){
			bn.num[i] = bn1.num[i];
			i++;
		}
		while(j < bn2.len){
			bn.num[j] = bn2.num[j];
			j++;
		}
	}else if(bn1.len<bn2.len){
	bn.len = bn2.len;
bn.num[0] = bn2.num[0];
int temp = 0, i = 1, j = 1;
while (i < bn1.len&&j < bn2.len) {
if (bn2.num[i] - bn1.num[j] - temp < 0) {
bn.num[i] = bn2.num[i] + 10 - bn1.num[j] - temp;
temp = 1;
}
else
{
bn.num[i] = bn2.num[i] - bn1.num[j] - temp;
temp = 0;
}
i++;
j++;
}
if (i < bn1.len)bn1.num[i] = bn1.num[i] - temp;
if (j < bn2.len)bn2.num[i] = bn2.num[i] - temp;
while (i < bn1.len) {
bn.num[i] = bn1.num[i];
i++;
}
while (j < bn2.len) {
bn.num[j] = bn2.num[j];
j++;
}
}
else {
for (int i = bn1.len; i > 0; i--) {
if (bn1.num[i] == bn2.num[i]) {
continue;
}
else if(bn1.num[i]>bn2.num[i])
{
bn.len = bn1.len;
bn.num[0] = bn1.num[0];
int temp = 0, i = 1, j = 1;
while (i < bn1.len&&j < bn2.len) {
if (bn1.num[i] - bn2.num[j] - temp < 0) {
bn.num[i] = bn1.num[i] + 10 - bn2.num[j] - temp;
temp = 1;
}
else
{
bn.num[i] = bn1.num[i] - bn2.num[j] - temp;
temp = 0;
}
i++;
j++;
}
if (i < bn1.len)bn1.num[i] = bn1.num[i] - temp;
if (j < bn2.len)bn2.num[i] = bn2.num[i] - temp;
while (i < bn1.len) {
bn.num[i] = bn1.num[i];
i++;
}
while (j < bn2.len) {
bn.num[j] = bn2.num[j];
j++;
}
}
else
{
bn.len = bn2.len;
bn.num[0] = bn2.num[0];
int temp = 0, i = 1, j = 1;
while (i < bn1.len&&j < bn2.len) {
if (bn2.num[i] - bn1.num[j] - temp < 0) {
bn.num[i] = bn2.num[i] + 10 - bn1.num[j] - temp;
temp = 1;
}
else
{
bn.num[i] = bn2.num[i] - bn1.num[j] - temp;
temp = 0;
}
i++;
j++;
}
if (i < bn1.len)bn1.num[i] = bn1.num[i] - temp;
if (j < bn2.len)bn2.num[i ] = bn2.num[i] - temp;
while (i < bn1.len) {
bn.num[i] = bn1.num[i];
i++;
}
while (j < bn2.len) {
bn.num[j] = bn2.num[j];
j++;
}
}
}
}
}
return bn;
}	
int main(){
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	struct bigNum bn1=toBigNum(str1);
	struct bigNum bn2 = toBigNum(str2);
	output(numadd(bn1,bn2));
	bn2.num[0]=bn2.num[0]*-1;
	output(numadd(bn1,bn2));
}
