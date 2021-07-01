#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	char name[20];
	int age;
	float *score;
}students[10000];
int cmp(const void *p1,const void *p2)
{
    struct student *c=(student*)p1;
    struct student *d=(student*)p2;
    if(c->score!=d->score) return (float*)d->score>(float*)c->score?1:-1;
    else if(c->age!=d->age&&c->score==d->score)
    return d->age>c->age?1:-1;
    else return d->name>c->name?1:-1;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	int i=0;
	while(i<n)
	{
		scanf("%s %d %lf",&students[i].name,&students[i].age,&students[i].score);
		i++;
	}
	qsort(students,n,sizeof(students[0]),cmp);
	i=0;
	while(i<n){
		printf("%s %d %.2lf\n",students[i].name,students[i].age,students[i].score );
		i++;
	}
	}
	
	return 0;
} 
