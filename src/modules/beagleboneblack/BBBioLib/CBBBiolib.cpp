#include "CBBBiolib.h"

//Initialize non-const static members
unsigned int CBBBiolib::sm_nLibUsers = 0;

CBBBiolib::CBBBiolib() {
	m_bHasJoined = false;
}

CBBBiolib::~CBBBiolib() {}

int CBBBiolib::initBBBioLib(){
	if(CBBBiolib::sm_nLibUsers == 0){
		if(0 != iolib_init()){
			return -1;
		}
	}
	CBBBiolib::sm_nLibUsers++;
	return 0;
}
int CBBBiolib::freeBBBioLib(){
	CBBBiolib::sm_nLibUsers--;
	if(CBBBiolib::sm_nLibUsers == 0){
		return iolib_free();
	}
	return 0;
}
int CBBBiolib::joinBBBioLib(){
	if(!m_bHasJoined){
		if(CBBBiolib::initBBBioLib() != -1){
			m_bHasJoined = true;
			return 0;
		}
		return -1;
	}
	return 0;
}
int CBBBiolib::leaveBBBioLib(){
	if(m_bHasJoined){
		CBBBiolib::freeBBBioLib();
		m_bHasJoined = false;
	}
	return 0;
}
