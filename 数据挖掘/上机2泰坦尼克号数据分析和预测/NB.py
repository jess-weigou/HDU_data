# 导入高斯朴素贝叶斯分类器
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score as accs


def fit(data):
    y_train = data["Survived"]
    del data["Survived"]
    x_train = data
    dtc = GaussianNB()
    clf = dtc.fit(x_train, y_train)
    l = x_train.columns.tolist()
    for i in range(0, len(l)):
        print(l[i], "\n\t\t存活：均值", clf.theta_[1][i], "方差", clf.sigma_[1][i])
        print("\t\t死亡：均值", clf.theta_[0][i], "方差", clf.sigma_[0][i])
    y_pred = dtc.predict(x_train)
    print('分类器训练准确度：%.3f%%' % (accs(y_pred, y_train) * 100))
    return clf
