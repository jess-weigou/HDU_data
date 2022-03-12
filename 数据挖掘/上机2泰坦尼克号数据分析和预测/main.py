import pandas as pd
import C4P5
import NB

train = pd.read_csv("train.csv")
del train["Cabin"]  # NaN值过多，删除
del train["Name"]
del train["Ticket"]
del train["PassengerId"]

train["Sex"].replace("male", 0, inplace=True)
train["Sex"].replace("female", 1, inplace=True)
train["Embarked"].replace("S", 0, inplace=True)
train["Embarked"].replace("C", 1, inplace=True)
train["Embarked"].replace("Q", 2, inplace=True)

train['Age'].fillna(train['Age'].dropna().mean(), inplace=True)  # 均值填充年龄
train.dropna(axis=0, how='any', inplace=True)
train.reset_index(drop=True, inplace=True)

test = pd.read_csv("test.csv")

test["Sex"].replace("male", 0, inplace=True)
test["Sex"].replace("female", 1, inplace=True)
test["Embarked"].replace("S", 0, inplace=True)
test["Embarked"].replace("C", 1, inplace=True)
test["Embarked"].replace("Q", 2, inplace=True)
del test["Cabin"]  # NaN值过多，删除
del test["Name"]
del test["Ticket"]
del test["PassengerId"]

test1=test.dropna(axis=0, how="any", inplace=False)

# clf = C4P5.fit(train)
# y_pred = clf.predict(test1)
# print(y_pred)


clf = NB.fit(train)
y_pred = clf.predict(test1)
print(y_pred)

# del train["Embarked"]
# test2=test.dropna(axis=0, how="any", inplace=False)
# clf = NB.fit(train)
# y_pred = clf.predict(test1)
# print(y_pred)