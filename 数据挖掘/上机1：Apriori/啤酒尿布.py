# coding=utf-8
"""
实现 Apriori 算法，并采用所写程序提取购物篮数据中的 频繁项集 和 强关联规则
参数设置：最小支持度计数 = 3，最小置信度 = 0.7
"""
min_sup = 3
min_conf = 0.7
# 最大 K 项集
K = 3


# apriori 算法
def apriori():
    # 1.读入数据
    data_set = load_data()
    # 2.计算每项的支持数
    C1 = create_C1(data_set)
    item_count = count_itemset1(data_set, C1)
    # 3.剪枝，去掉支持数小于最小支持度数的项
    L1 = generate_L1(item_count)
    # 4.连接
    # 5.扫描前一个项集，剪枝
    # 6.计数，剪枝
    # 7.重复4-6，直到得到最终的 K 项频繁项集
    Lk_copy = L1.copy()
    L = []
    L.append(Lk_copy)
    for i in range(2, K + 1):
        Ci = create_Ck(Lk_copy, i)
        Li = generate_Lk_by_Ck(Ci, data_set)
        Lk_copy = Li.copy()
        L.append(Lk_copy)
    # 8.输出频繁项集及其支持度数
    print('频繁项集\t支持度计数')
    support_data = {}
    for item in L:
        for i in item:
            print(list(i), '\t', item[i])
            support_data[i] = item[i]
    # 9.对每个关联规则计算置信度，保留大于最小置信度的频繁项为 强关联规则
    strong_rules_list = generate_strong_rules(L, support_data, data_set)
    strong_rules_list.sort(key=lambda result: result[2], reverse=True)
    print("\nStrong association rule\nX\t\t\tY\t\tconf")
    for item in strong_rules_list:
        print(list(item[0]), "\t", list(item[1]), "\t", item[2])


# 读入数据
def load_data():
    # 事务ID 购买商品
    data = {'001': '牛奶，面包，黄油',
            '002': '牛奶，啤酒，尿布',
            '003': '面包，黄油，饼干',
            '004': '牛奶，尿布，饼干',
            '005': '啤酒，尿布',
            '006': '牛奶，尿布，面包，黄油',
            '007': '啤酒，饼干',
            '008': '啤酒，尿布，饼干',
            '009': '牛奶，尿布，面包，黄油',
            '010': '尿布，面包，黄油'}
    data_set = []
    for key in data:
        item = data[key].split('，')
        data_set.append(item)
    return data_set


# 构建 1-项集
def create_C1(data_set):
    C1 = set()
    for t in data_set:
        for item in t:
            item_set = frozenset([item])
            C1.add(item_set)
    return C1


# 计算给定数据每项及其支持数，第一次
def count_itemset1(data_set, C1):
    item_count = {}
    for data in data_set:
        for item in C1:
            if item.issubset(data):
                if item in item_count:
                    item_count[item] += 1
                else:
                    item_count[item] = 1
    return item_count


# 生成剪枝后的 L1
def generate_L1(item_count):
    L1 = {}
    for i in item_count:
        if item_count[i] >= min_sup:
            L1[i] = item_count[i]
    return L1


# 判断是否该剪枝
def is_apriori(Ck_item, Lk_copy):
    for item in Ck_item:
        sub_Ck = Ck_item - frozenset([item])
        if sub_Ck not in Lk_copy:
            return False
    return True


# 生成 k 项商品集，连接操作
def create_Ck(Lk_copy, k):
    Ck = set()
    len_Lk_copy = len(Lk_copy)
    list_Lk_copy = list(Lk_copy)
    for i in range(len_Lk_copy):
        for j in range(1, len_Lk_copy):
            l1 = list(list_Lk_copy[i])
            l2 = list(list_Lk_copy[j])
            l1.sort()
            l2.sort()
            if l1[0:k-2] == l2[0:k-2]:
                Ck_item = list_Lk_copy[i] | list_Lk_copy[j]
                # 扫描前一个项集，剪枝
                if is_apriori(Ck_item, Lk_copy):
                    Ck.add(Ck_item)
    return Ck


# 生成剪枝后的 Lk
def generate_Lk_by_Ck(Ck, data_set):
    item_count = {}
    for data in data_set:
        for item in Ck:
            if item.issubset(data):
                if item in item_count:
                    item_count[item] += 1
                else:
                    item_count[item] = 1
    Lk2 = {}
    for i in item_count:
        if item_count[i] >= min_sup:
            Lk2[i] = item_count[i]
    return Lk2


# 产生强关联规则
def generate_strong_rules(L, support_data, data_set):
    strong_rule_list = []
    sub_set_list = []
    # print(L)
    for i in range(0, len(L)):
        for freq_set in L[i]:
            for sub_set in sub_set_list:
                if sub_set.issubset(freq_set):
                    # 计算包含 X 的交易数
                    sub_set_num = 0
                    for item in data_set:
                        if (freq_set - sub_set).issubset(item):
                            sub_set_num += 1
                    conf = support_data[freq_set] / sub_set_num
                    strong_rule = (freq_set - sub_set, sub_set, conf)
                    if conf >= min_conf and strong_rule not in strong_rule_list:
                        print(list(freq_set-sub_set), " => ", list(sub_set), "conf: ", conf)
                        strong_rule_list.append(strong_rule)
            sub_set_list.append(freq_set)
    return strong_rule_list


if __name__ == '__main__':
    # 运行 Apriori 算法
    apriori()
