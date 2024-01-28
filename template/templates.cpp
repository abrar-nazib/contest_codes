void show_vector_string(vector<string> &vect)
{
    for (auto elem : vect)
    {
        cout << elem << " ";
    }
    cout << "\n";
}
template <typename T>
void print_queue(T &q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
    }
    cout << "\n"
}