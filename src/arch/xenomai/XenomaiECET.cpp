
#include <XenomaiECET.h>

CXenomaiECET::CXenomaiECET(): CEventChainExecutionThread() {
}

CXenomaiECET::~CXenomaiECET() {

}

void CXenomaiECET::changeExecutionState(EMGMCommandType pa_unCommand, uint pa_nPolicy, uint pa_nPriority){
  switch (pa_unCommand){
    case cg_nMGM_CMD_Start:
      if(!isAlive()){
        //only start the thread when we are not already running
    	  CThread::start(pa_nPolicy,pa_nPriority);
      }
      break;
    case cg_nMGM_CMD_Kill:
    	CEventChainExecutionThread::clear();
	  end();
      break;
    case cg_nMGM_CMD_Stop:
      end();
      break;
    default:
      break;
  }
}

void CXenomaiECET::changeThreadAttributes(uint pa_nPolicy, uint pa_nPriority){
	pthread_t l_stThreadID = CThread::getThreadID();
	if(0 != l_stThreadID){
			//Check input parameters range
			if(pa_nPriority > 99){
				DEVLOG_ERROR("Error RT thread priority is not within [0-99].\n");
				return;
			}
			if(pa_nPolicy != SCHED_FIFO && pa_nPolicy != SCHED_RR){
				DEVLOG_ERROR("Error RT thread policy is unknown.\n");
				return;
			}
			struct sched_param sParam;
			sParam.__sched_priority = pa_nPriority;
			pthread_setschedparam(l_stThreadID, pa_nPolicy, &sParam);
	}
}
