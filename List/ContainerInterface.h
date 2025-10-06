#ifndef CONTAINERINTERFACE_H_
#define CONTAINERINTERFACE_H_

class BADINDEX {};

template <class T>
class containerInterface
{
   public:
	 virtual containerInterface <T>& pushFront(const T) =0;
	 virtual containerInterface <T>& pushBack(const T)  =0;
	 virtual containerInterface <T>& popFront( )        =0;
	 virtual containerInterface <T>& popBack( )         =0;
	 virtual int  getSize() const                       =0;
	 virtual bool empty() const                         =0;
	 virtual T    front() const                         =0;
	 virtual T    back() const                          =0;
	 virtual T&   operator [](int)                      =0;
	 virtual void erase()                               =0;
	 virtual ~containerInterface(){};
};

#endif /* CONTAINERINTERFACE_H_ */
