'''
 競技プログラミング勉強会用のコード
 ABC007 C 幅優先探索
 Python 解答例
'''

from collections import deque

def solve():
    R, C = map(int, input().split())  # 迷路のサイズ
    sy, sx = map(lambda x: int(x) - 1, input().split())  # スタートの座標
    gy, gx = map(lambda x: int(x) - 1, input().split())  # ゴールの座標
    maze_map = [input() for _ in range(R)]  # 迷路
    queue = deque([(sy, sx, 0)])  # 幅優先探索用のキュー
    is_already_arrived = [[True if sy == i and sx == j else False for j in range(C)] for i in range(R)]  # すでにたどり着いたか

    # ここから幅優先探索
    # 今回はゴールしないパターンは存在しない
    while True:
        now_pos = queue.popleft() # 現在地を取り出す

        # もしゴールなら出力
        if now_pos[0] == gy and now_pos[1] == gx:
            print(now_pos[2])
            break

        # 4方向を確認する
        for y, x in [[0, 1], [0, -1], [-1, 0], [1, 0]]:
            next_pos_y, next_pos_x = now_pos[0] + y, now_pos[1] + x  # 次の座標
            # 範囲外に出ない
            if 0 <= next_pos_y < R and 0 <= next_pos_x < C:
                # まだ行ったことのない道であれば
                if maze_map[next_pos_y][next_pos_x] == '.' and not is_already_arrived[next_pos_y][next_pos_x]:
                    queue.append((next_pos_y, next_pos_x, now_pos[2] + 1))  # キューに追加
                    is_already_arrived[next_pos_y][next_pos_x] = True  # 到達した

if __name__ == '__main__':
    solve()
