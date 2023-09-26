#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#if __has_include(<concepts>)
#include <concepts>
#endif
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

#if __cpp_concepts >= 201907
template<std::signed_integral T>
#else
template<class T>
#endif
class union_find{
	T tree[200000];
public:
	union_find(T n){
		memset(tree, -1, sizeof tree);
	}
	T root(const T &index){
		return tree[index] < 0 ? index : tree[index] = root(tree[index]);
	}
	void unite(T index1, T index2){
		index1 = root(index1);
		index2 = root(index2);
		if(index1 != index2){
			if(-tree[index1] < -tree[index2]){
				tree[index1] = index2;
			}else{
				tree[index1] -= tree[index1] == tree[index2];
				tree[index2] = index1;
			}
		}
	}
	bool is_united(T index1, T index2){
		return root(index1) == root(index2);
	}
};


int main(){
	std::size_t n = 0;
	unsigned q = 0;

	struct stat input_stat;
	fstat(0, &input_stat);
	char *input = (char *)mmap(NULL, input_stat.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
	unsigned i;
	for(i = 0; input[i] != ' '; ++i) n = n * 10 + (input[i] - '0');
	for(++i; input[i] != '\n'; ++i) q = q * 10 + (input[i] - '0');

	static char output[400000];
	std::size_t output_count = 0;

	union_find<int> tree(n);
	for(unsigned j = 0; j < q; ++j){
		char t = input[i + 1];
		int u = 0, v = 0;
		for(i += 3; input[i] != ' '; ++i) u = u * 10 + (input[i] - '0');
		for(++i; input[i] != '\n'; ++i) v = v * 10 + (input[i] - '0');
		if(t == '0'){
			tree.unite(u, v);
		}else{
			output[output_count] = '0' + tree.is_united(u, v);
			output[output_count + 1] = '\n';
			output_count += 2;
		}
	}

	write(1, output, output_count);
}
