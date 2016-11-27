//Ring-0	your crc_ring need lengt 32 characters - If it exceeds 32 characters delete the last characters until 32.
//d7d7da735c6d310f884558f2313aa457		
#define CRC_RING "d7d7da735c6d310f884558f2313aa457" //paste your CPT32 here <<<<<<
struct {
  char key[10];
} personA, person_copyA;

struct {
  char macc[18];
} personB, person_copyB;

struct {
  char hdid[33];
} personC, person_copyC;


struct {
  char keyzim[34];
} personD, person_copyD;


int statusS;

