/*
 * queue.h
 *
 *  Created on: 2014-10-3
 *      Author: qianqians
 */
#ifndef _queue_h
#define _queue_h

#include "typedef.h"

namespace Fossilizid{
namespace remoteq {

/*
 * create a QUEUE
 */
QUEUE queue();

enum event_type{
	event_type_none,
	event_type_reliable_accept,
	event_type_reliable_recv,
	event_type_reliable_disconnect,
	event_type_fast_accept,
	event_type_fast_recv,
	event_size,
};

struct EVENT{
	union { ACCEPTOR acp; CHANNEL ch; } handle;
	event_type type;
};

/*
 * get EVENT from QUEUE
 */
EVENT queue(QUEUE que);

} /* namespace remoteq */
} /* namespace Fossilizid */

#endif //_queue_h