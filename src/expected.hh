#ifndef EXPECTED_H
#define EXPECTED_H

// error handling
template <typename T, typename E>
class expected {

public:
  T& get()
  {
    if (!m_valid) {
      throw std::logic_error("Missing a value!");
    }
    return m_value;
  }

  E& error() {
    if (m_valid) {
      throw std::logic_error("There is no error");
    }
    return m_error;
  }

  // constructing a new value of expected<T, E>
  template <typename... Args>
  static expected success(Args&&... params)
  {
    expected result; // default constructor that creates uninitialized
		     // union
    result.m_valid = true; // initializes the union tag. You'll have a
			   // valid value inside

    // calls placement new to initialize the value of type T in the
    // memory location of m_value
    new (&result.m_value) T(std::forward<Args>(params)...);

    return result;
  }

  template <typename... Args>
  static expected error(Args&&... params)
  {
    // creating the error instance is the same, apart from calling the
    // constructor for type E instead of the constructor of T
    expected result;
    result.m_valid = false;
    new (&result.m_error) E(std::forward<Args>(params)...);
    return result;
  }

private:
  union {
    T m_value;
    E m_error;
  };

  bool m_valid;
};

#endif /* EXPECTED_H */
