//clasa care contine atributele persoanei 
class Info{	    
	int varsta;
	char *nume;
	public:
		Info();
		~Info();
		Info &operator=(const Info &);
		Info(const Info &);
		int get_varsta() const;	
		friend class Lista;
};
