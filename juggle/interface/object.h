/*
 * object.h
 *
 *  Created on: 2015-1-11
 *      Author: qianqians
 */
#ifndef _object_h
#define _object_h

#include <string>
#include <cstdint>
#include <vector>

namespace Fossilizid{
namespace juggle{

class nullobjecttype;
typedef nullobjecttype * nullobject;

class object{
public:
	/*
	 * object is empty
	 */
	virtual bool empty() const = 0;

	/*
	 * clear the object, set object to null
	 */
	virtual void clear() = 0;

	/*
	 * get the object value when object is value type
	 */
	virtual bool asbool() const = 0;
	virtual int64_t asint() const = 0;
	virtual double asfloat() const = 0;
	virtual std::string asstring() const = 0;

	/*
	 * judge the object type
	 */
	virtual bool isnull() const = 0;
	virtual bool isbool() const = 0;
	virtual bool isint() const = 0;
	virtual bool isfloat() const = 0;
	virtual bool isstring() const = 0;
	virtual bool isarray() const = 0;
	virtual bool ismap() const = 0;

	/*
	 * get the object size
	 * effectived when object type is array or map 
	 */
	virtual size_t size() const = 0;
	
	/*
	 * acess the object as a array
	 */
	virtual object & operator[](int index) = 0;
	virtual const object &operator[](int index) const = 0;

	virtual object & append(const bool & other) = 0;
	virtual object & append(const int64_t & other) = 0;
	virtual object & append(const double & other) = 0;
	virtual object & append(const std::string & other) = 0;
	virtual object & append(boost::shared_ptr<object> other) = 0;
	
	virtual bool erase(const int index) = 0;

	/*
	 * acess the object as a map
	 */
	virtual bool hasfield(const std::string & key) const = 0;
	
	virtual std::pair<std::string, boost::shared_ptr<object> > getitem(int index) = 0;

	virtual object &operator[](const std::string & key) = 0;
	virtual const object &operator[](const std::string & key) const = 0;
	
	virtual bool erase(const std::string & key) = 0;

	/*
	 * set value
	 */
	virtual void operator =(const nullobject other) = 0;
	virtual void operator =(const bool & other) = 0;
	virtual void operator =(const int64_t & other) = 0;
	virtual void operator =(const double & other) = 0;
	virtual void operator =(const std::string & other) = 0;
	virtual void operator =(const char * other) = 0;
	virtual void operator =(boost::shared_ptr<object> other) = 0;

};

class nullobjecttype{
public:
	nullobjecttype(){
	}
};

} /* namespace juggle */
} /* namespace Fossilizid */

#endif //_object_h