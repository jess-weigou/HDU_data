# 导入决策树模型
from sklearn import tree
# 决策树可视化

from sklearn.metrics import accuracy_score as accs


def fit(data):
    y_train = data["Survived"]
    del data["Survived"]
    x_train = data
    dtc = tree.DecisionTreeClassifier(criterion="entropy")
    clf = dtc.fit(x_train, y_train)  # 训练决策树
    dot_data = tree.export_graphviz(clf, out_file=None, feature_names=x_train.columns.tolist())  # 导出决策树
    y_pred = dtc.predict(x_train)
    print('分类树训练准确度：%.3f%%' % (accs(y_pred, y_train) * 100))
    return clf
