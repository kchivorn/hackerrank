#!/bin/ruby

q = gets.strip.to_i

def dfs(node, adj_list, cluster, visited)
  visited[node] = true
  cluster << node
  for i in adj_list[node]
    dfs(i, adj_list, cluster, visited) unless visited[i]
  end
end

q.times do
  c, r, cl, cr = gets.strip.split(' ').map(&:to_i)
  visited = Array.new(c+1) { false }
  adj_list = Array.new(c+1) { [] }
  network = []
  total_cost = 0

  r.times do
    c1, c2 = gets.strip.split(' ').map(&:to_i)
    adj_list[c1] << c2
    adj_list[c2] << c1
  end

  if cl <= cr
    total_cost = cl * c
    puts total_cost
    next
  end

  c.times do |i|
    cluster = []
    unless visited[i+1]
      dfs(i+1, adj_list,cluster, visited)
      network << cluster
    end
  end

  network.each do |cluster|
     total_cost += ((cluster.length - 1) * cr + cl)
  end

  puts total_cost
end
