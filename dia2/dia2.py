def parse_lines(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    return [line.strip() for line in lines]

def check_input(input):
    first = True
    ascending = False
    safe = True
    for i in range(len(input) - 1):
        step =  input[i + 1] - input[i]
        if abs(step) > 3 or abs(step) < 1:
            safe = False
            break
        if step > 0:
            if(first):
                ascending = True
                first = False
            elif not ascending:
                safe = False
                break
        elif step < 0:
            if(first):
                ascending = False
                first = False
            elif ascending:
                safe = False
                break
        else:
            safe=False
            break
    if safe:
        return True
    return False

def part2_simple(inputs):
    result = 0
    for input in inputs:
        input = list(map(int, input))
        # Check with all nums
        if(check_input(input)):
            result+=1
        else:
            for i in range(len(input)):
                new_input = input[:i] + input[i+1:]
                if(check_input(new_input)):
                    result+=1
                    break

    print(result)
    pass




# def part1(inputs):
#     result = 0
#     for input in inputs:
#         input = list(map(int, input))
#         print(input)
#         steps = 0
#         safe = True
#         for i in range(len(input) - 1):
#             step =  input[i + 1] - input[i]
#             if abs(step) > 3 or abs(step) < 1:
#                 safe = False
#                 break
#             new_steps = steps + step
#             if abs(new_steps) <= abs(steps):
#                 safe = False
#                 break
#             steps = new_steps
#         if safe:
#             print("correct")
#             result += 1
#     print(result)
#     pass

if __name__ == "__main__":
    lines = parse_lines('input.txt')
    inputs = []
    for line in lines:
        inputs.append(line.split(' '))
    part2_simple(inputs)