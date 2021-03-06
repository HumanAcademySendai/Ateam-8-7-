/**
 *  MotionQueueManager.h
 *
 *  Copyright(c) Live2D Inc. All rights reserved.
 *  [[ CONFIDENTIAL ]]
 */
#ifndef __LIVE2D_MOTION_QUEUE_MANAGER_H__
#define __LIVE2D_MOTION_QUEUE_MANAGER_H__


#include "../memory/LDObject.h"
#include "../ALive2DModel.h"

#include "../type/LDVector.h"
#include "AMotion.h"

//--------- LIVE2D NAMESPACE ------------
namespace live2d
{
	class Live2DMotion ;
	class MotionQueueEnt ;
	class MemoryParam ;


	
	class MotionQueueManager : public live2d::LDObject 
	{
	public:
		MotionQueueManager();
		virtual ~MotionQueueManager();
		
		// æ?®ã?ã¢ã¼ã·ã§ã³ãéå§ãã?
		// åãã¿ã¤ãã?ã¢ã¼ã·ã§ã³ãæ¢ã«ããå ´åã?ãæ¢å­ã?ã¢ã¼ã·ã§ã³ã«çµäº?ã©ã°ãç«ã¦ããã§ã¼ãã¢ã¦ããéå§ãããã?
		int startMotion( AMotion * motion , bool autoDelete ) ;
		
		// ã¢ã?«ã®ãã©ã¡ã¼ã¿ãè¨­å®ã?æ´æ°ãã?åããåæ ãã??
		bool updateParam( live2d::ALive2DModel * model ) ;

		//  å¨ã¦ã®ã¢ã¼ã·ã§ã³ãçµäº?ã¦ã?ã?
		bool isFinished() ;
		
		// å¼æ°ã§æ?®ããã¢ã¼ã·ã§ã³ãçµäº?ã¦ã?ããè¿ãã?0.8.09è¿½å?¼?
		bool isFinished(int motionQueueEntNo ) ;


		//  å¨ã¦ã®ã¢ã¼ã·ã§ã³ãåæ­¢ãã
		void stopAllMotions() ;

		//  ã¢ã¼ã·ã§ã³ã®éå§ã?çµäº?ã?³ããã?
		void setMotionDebugMode( bool f ){ this->motionDebugMode = f ; }

		//  MotionQueueEntãåå¾?
		MotionQueueEnt* getMotionQueueEnt( int entNo ) ;
	    
	#if L2D_VERBOSE
		void DUMP() ;
	#endif

	private:
		live2d::LDVector<MotionQueueEnt *> *motions ;

		bool motionDebugMode ;// ã¢ã¼ã·ã§ã³ã®åçã»åæ­¢ããã³ããããã©ã°

		live2d::MemoryParam*  memoryManagement ;
		live2d::AMemoryHolder*	memoryHolderFixedMain ;
	};

}
//--------- LIVE2D NAMESPACE ------------

#endif		// __LIVE2D_MOTION_QUEUE_MANAGER_H__
