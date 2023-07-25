 ui n, q, v, x, l, r;
    cin >> n >> q;
    ui a[n];
    for (ui i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ui i = 0; i < q; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> v;
            for (ui i = 0; i < n; i++)
            {
                a[i] = min(a[i], v);
            }
        }
        else if (x == 2)
        {
            for (ui i = 0; i < n; i++)
            {
                a[i] += i + 1;
            }
        }
        else if (x == 3)
        {
            cin >> l >> r;
            ui sum = 0;
            for (ui i = l - 1; i < r; i++)
            {
                sum += a[i];
            }
            cout << sum << "\n";
        }
    }