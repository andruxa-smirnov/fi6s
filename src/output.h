#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <stdio.h>
#include <stdint.h>

enum {
	OUTPUT_STATUS_OPEN = 0,
	OUTPUT_STATUS_CLOSED,
};

enum {
	OUTPUT_PROTO_TCP = 0,
	OUTPUT_PROTO_UDP,
};

struct outputdef {
	void (*begin)(FILE *);
	void (*output_status)(FILE *, uint64_t /*ts*/, const uint8_t * /*addr*/, int /*proto*/, uint16_t /*port*/, uint8_t /*ttl*/, int /*status*/);
	void (*output_banner)(FILE *, uint64_t /*ts*/, const uint8_t * /*addr*/, int /*proto*/, uint16_t /*port*/, const char * /*banner*/, uint32_t /*bannerlen*/);
	void (*end)(FILE *);
	int postprocess;
};

const struct outputdef output_list;
const struct outputdef output_json;
const struct outputdef output_binary;

#endif // _OUTPUT_H
