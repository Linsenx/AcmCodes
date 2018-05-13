#include<iostream>
#include<cstdlib> 
#include<cstring>
using namespace std;

int Ss,Sn,Sm;
class glass{
	public :
	  int size;
      int water;
      glass(int size = 0,int water = 0){
		this->size = size;
		this->water = water;
	  }
};
class glassState{
	public :
	   glass s,n,m;
	   int step;
	public :
	   glassState(int Ss,int Sn,int Sm){
			s = glass(Ss,Ss);
			n = glass(Sn,0);
			m = glass(Sm,0);
	   }
	   glassState(){
	   		s = glass();
			n = glass();
			m = glass();
	   }
	   void pull(glass &a,glass &b){ //a中的水倒入b中 
			if(a.water+b.water >= b.size){
				a.water = a.water + b.water - b.size;
				b.water = b.size;
			}else{
				b.water = a.water + b.water;
				a.water = 0;
			}
	    }
};
glassState queue[10005];
int tail = 0,front = 0;
bool vis[101][101][101];//状态判重 
bool isEnd(int x,int y){
	return (2*x == y);
}
int bfs(){
	glassState tmp = glassState(Ss,Sn,Sm);
	glassState em = glassState(Ss,Sn,Sm);
	em.step = 0;
	queue[tail++] = em;
	while(tail != front){
		glassState e = queue[front];
		front++;
		tmp = e;
		e.pull(e.s,e.n);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
			if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
		e = tmp;
		e.pull(e.s,e.m);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
			if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
	    e = tmp;
		e.pull(e.m,e.n);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
			if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
		e = tmp;
		e.pull(e.m,e.s);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
				if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
		e = tmp;
		e.pull(e.n,e.m);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
			if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
		e = tmp;
		e.pull(e.n,e.s);
		if(!vis[e.s.water][e.n.water][e.m.water]){
			vis[e.s.water][e.n.water][e.m.water] = true;
			if(isEnd(e.s.water,e.s.size)){
				return e.step+1;
			}
			e.step ++; 
			queue[tail++] = e;
		}
	}
	return -1;
}
int main(){
	while(cin>>Ss>>Sn>>Sm && (Ss || Sn || Sm)){
		if(Ss%2 == 1){
			cout<<"NO"<<endl;
			continue;
		}
		memset(vis,false,sizeof(vis));
		vis[Ss][0][0] = true;
		tail = 0,front = 0;
		int ans = bfs();
		if(ans < 0){
			cout<<"NO"<<endl;
		}else{
			cout<<ans<<endl;
		}
//		cout<<front<<"  "<<tail<<endl;
	}
	return 0;
}