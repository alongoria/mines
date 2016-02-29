#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>
#include <unordered_map>

class markov_model {
public:
	markov_model(std::string s, int k) { data = s; order = k; }
	virtual std::string generate(int size) = 0;

protected:
	std::string data;
	int order;
};

class brute_model : public markov_model {
public:
	brute_model(std::string s, int k) : markov_model(s, k) {}
	virtual std::string generate(int size);
};

class map_model : public markov_model {
public:
	map_model(std::string s, int k) : markov_model(s, k) {}
	virtual std::string generate(int size);
};

class umap_model : public markov_model {
public:
	umap_model(std::string s, int k) : markov_model(s, k) {}
	virtual std::string generate(int size);
};

class word_model : public markov_model {
public:
	word_model(std::string s, int k) : markov_model(s, k) {}
	virtual std::string generate(int size);
};

#endif
