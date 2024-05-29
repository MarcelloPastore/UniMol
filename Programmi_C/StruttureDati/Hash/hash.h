typedef struct _hash* hash;

hash hash_new(int capacity);
void destroy_hash(hash h);

void hash_set(hash h, char* key, int value);
int hash_get(hash h, charh* key);
int hash_size(hash h);