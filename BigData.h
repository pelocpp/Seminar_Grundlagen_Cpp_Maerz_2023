class BigData
{
private:
    int*  m_data;
    int   m_count;

public:
    BigData();                   // default / standard c'tor
    BigData(int count);          // user-defined c'tor
    BigData(const BigData&);     // copy - c'tor

    // Operators
    BigData& operator= (const BigData&);  // Wertzuweisung / Assignment

    ~BigData();   // Destruktor
};