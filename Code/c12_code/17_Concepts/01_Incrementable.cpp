template <typename T>
concept Incrementable = requires(T x) { x++; ++x; };

//template <Incrementable T>
//void process(const T& t)
//{
//}

//template <typename T> requires Incrementable<T>
//void process(const T& t)
//{
//}

//template <typename T> requires requires(T x) { x++; ++x; }
//void process(const T& t)
//{
//}

//template <typename T>
//void process(const T& t) requires Incrementable<T>
//{
//}

void process(const Incrementable auto& t)
{
}

int main()
{
	process(123);
}