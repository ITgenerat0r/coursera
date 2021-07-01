#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Block
{
public:
	Block(){
		w = 0;
		h = 0;
		d = 0;
	};

	uint64_t GetVolume() const {
		uint64_t v = w;
		v *= h;
		v *= d;
		return v;
	}

	uint16_t GetW() const {
		return w;
	}

	uint16_t GetH() const {
		return h;
	}

	uint16_t GetD() const {
		return d;
	}

	void SetW(const uint16_t& v){
		w = v;
	}
	void SetH(const uint16_t& v){
		h = v;
	}
	void SetD(const uint16_t& v){
		d = v;
	}
private:
	uint16_t w, h, d;
	
};

istream& operator>>(istream& stream, Block& block){
	int16_t w, h, d;
	stream >> w >> h >> d;
	//cout << "test " << w << ' ' << h << ' ' << d << endl;
	block.SetW(w);
	block.SetH(h);
	block.SetD(d);
	return stream;
}


int main(){
	// long long int imin = std::numeric_limits<int>::min();
	// long long int imax = std::numeric_limits<int>::max();
	// cout << "int " << imin << ", " << imax << ",   "  << sizeof(int) << endl;

	// imin = std::numeric_limits<int8_t>::min();
	// imax = std::numeric_limits<int8_t>::max();
	// cout << "int8_t " << imin << ", " << imax << endl;

	// imin = std::numeric_limits<uint8_t>::min();
	// imax = std::numeric_limits<uint8_t>::max();
	// cout << "uint8_t " << imin << ", " << imax << endl;


	// imin = std::numeric_limits<int16_t>::min();
	// imax = std::numeric_limits<int16_t>::max();
	// cout << "int16_t " << imin << ", " << imax << endl;

	// imin = std::numeric_limits<uint16_t>::min();
	// imax = std::numeric_limits<uint16_t>::max();
	// cout << "uint16_t " << imin << ", " << imax << endl;



	// imin = std::numeric_limits<int64_t>::min();
	// imax = std::numeric_limits<int64_t>::max();
	// cout << "int64_t " << imin << ", " << imax << endl;







	int n;
	int16_t r;
	uint64_t summ = 0;
	cin >> n;
	cin >> r;
	vector<Block> blocks(n);
	for(Block& block : blocks){
		cin >> block;
	}

	for(const Block& block : blocks){
		// cout << "summ = " << summ << endl;
		// cout << "r = " << r << endl;
		// cout << block.GetW() << " " << block.GetH() << " " << block.GetD() << endl;
		// cout << "volume = " << block.GetVolume() << endl << endl;
		summ += static_cast<uint64_t>(r) * static_cast<uint64_t>(block.GetVolume());
	}
	cout << summ;
	return 0;
}