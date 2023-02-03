if (c == 'U')
                y++;

            if (c == 'D')
                y--;

            if (c == 'R')
                x++;

            if (c == 'L')
                x--;

            if (x == 1 && y == 1)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            cout << "NO\n";
        }