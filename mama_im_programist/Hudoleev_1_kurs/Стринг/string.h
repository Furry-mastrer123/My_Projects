class String
{
	private:
	char* str;
	int len;
	public:
	String();
	String(const char*);
	~String();
	void print();
	String operator +(String& op1);
	String& operator =(const String& op2);
	String(const String&);
	bool operator >(String& op3);
	void ToUpper();
	void Tolower();
};