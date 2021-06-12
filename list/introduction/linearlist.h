template<class T>
class LinearList
{
public:
    virtual LinearList() {};
    virtual ~LinearList() {};

    virtual bool is_empty() const = 0;
    virtual unsigned int size() const = 0;
    virtual T& get(int index) const = 0;

    virtual int index_of(const T& element) const = 0;
    virtual void erase(int index) = 0;
    virtual void insert(int pos, const T& element) = 0;

    virtual operator <<() const = 0;
};