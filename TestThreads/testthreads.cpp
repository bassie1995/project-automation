#include <thread>
#include <iostream>
#include <chrono>

#define ENDLDARM endl

using namespace std;	

void doeiets(){
	cout<<"de test werkt"<<ENDLDARM;
	this_thread::sleep_for(chrono::seconds(2));
	cout<<"matt damon 4sleepy6u"<<ENDLDARM;
	system("/usr/local/bin/groupsocketlisten ip:127.0.0.1");
}

void doeniets(){
	cout<<"ik doe niets"<<ENDLDARM;
	this_thread::sleep_for(chrono::seconds(5));
}

int main(){
	system("/usr/local/bin/eibd -D -S -T -i --eibaddr=0.0.1 --daemon=/var/log/eibd.log --no-tunnel-client-queuing ipt:145.52.126.174");
	thread t1(doeiets);
	thread t2(doeniets);
	cout<<"test"<<ENDLDARM;
	
	t1.join();
	t2.join();
	
	//while(1){
	//}
	
}
