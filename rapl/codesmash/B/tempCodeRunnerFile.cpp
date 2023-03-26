        for (ui i = 0; i < n; i++)
        {
            cin >> idx >> val;

            sc_map = update_map_insert(sc_map, scores[idx - 1] + val);
            sc_map = update_map_remove(sc_map, scores[idx - 1]);
            scores[idx - 1] += val;
            cout << sc_map.size() << "\n";
        }