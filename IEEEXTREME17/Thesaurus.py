#5%
import xml.etree.ElementTree as ET
import re


lines=[]
while True:
    try:
        line=input()
        lines.append(line.lower())
        if "#end" in line:
            break
    except EOFError:
        break

data = '\n'.join(lines)
end="</thesaurus>"
data.find(end)
xml_data=data[:data.find(end)+len(end)]
text=data[data.find(end)+len(end):]
root = ET.fromstring(xml_data)
adjacencyList = {}
reverseList={}
mapper = {}
nodes=set()
for term in root.findall('terminfo'):
    name=term.find('t').text
    mapper[name] = name
    nodes.add(name)
    for nt in term.findall('nt'):
        if name not in adjacencyList:
            adjacencyList[name] = set()
        if nt.text not in reverseList:
            reverseList[nt.text] = set()
        adjacencyList[name] .add(nt.text)
        reverseList[nt.text].add(name)
    for bt in term.findall('bt'):
        if bt.text not in adjacencyList:
            adjacencyList[bt.text] = set()
        if name not in reverseList:
            reverseList[name] = set()
        reverseList[name].add(bt.text)
        adjacencyList[bt.text].add(name)
    for uf in term.findall('uf'):
        mapper[uf.text]=name

newAdjacencyList = {}
newReverseList = {}
for key in adjacencyList:
    newAdjacencyList[mapper[key]] = set()
    for value in adjacencyList[key]:
        newAdjacencyList[mapper[key]].add(mapper[value])
for key in reverseList:
    newReverseList[mapper[key]] = set()
    for value in reverseList[key]:
        newReverseList[mapper[key]].add(mapper[value])
adjacencyList=newAdjacencyList
reverseList=newReverseList
counter={}

visited=set()


for node in mapper:
    if mapper[node] not in counter:
        counter[mapper[node]]=0
    for match in re.finditer(r"\b"+node+r"\b",text):
        counter[mapper[node]]+=1

def countChildren(node):
    if node in visited:
        return
    visited.add(node)
    if node in adjacencyList:
        for child in adjacencyList[node]:
            countChildren(child)
            counter[node]+=counter[child]
    elif node not in counter:
        counter[node]=0
    return
L=[]
for node in nodes:
    countChildren(node)
    if node not in reverseList:
        L.append((node,counter[node]))
L.sort(key=lambda x:(x[1],x[0]),reverse=True)
for(i,j) in L:
    i=i.capitalize()
    print(f"{i} = {j}")
