#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

int tree[200000];
int root(const int &index){
	return tree[index] < 0 ? index : tree[index] = root(tree[index]);
}

unsigned n, q;
struct stat input_stat;
unsigned i;
char output[400000];
unsigned output_count;

int main(){
	fstat(0, &input_stat);
	char *input = (char *)mmap(NULL, input_stat.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
	for(i = 0; input[i] != ' '; ++i) n = n * 10 + (input[i] - '0');
	for(++i; input[i] != '\n'; ++i) q = q * 10 + (input[i] - '0');

	memset(tree, -1, sizeof tree);
	memset(output, '\n', q * 2);
	for(unsigned j = 0; j < q; ++j){
		char t = input[i + 1];
		int u = 0, v = 0;
		for(i += 3; input[i] != ' '; ++i) u = u * 10 + (input[i] - '0');
		for(++i; input[i] != '\n'; ++i) v = v * 10 + (input[i] - '0');
		if(t == '0'){
			u = root(u);
			v = root(v);
			if(u != v){
				if(-tree[u] < -tree[v]){
					tree[u] = v;
				}else{
					tree[u] -= tree[u] == tree[v];
					tree[v] = u;
				}
			}
		}else{
			output[output_count] = '0' + (root(u) == root(v));
			output_count += 2;
		}
	}

	write(1, output, output_count);
}
