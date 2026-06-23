def main():
    with open("input.txt", "r") as input:
        inparts = input.read().split("\n\n")

        grid = list(map(lambda x: x.split(" "), inparts[0].split("\n")))
        for i in range(len(grid)):
            grid[i] = list(map(lambda x: int(x), grid[i]))
        print(grid)

        instructions = inparts[1].split("\n")
        print(instructions)

        tca = inparts[2].split("\n")[:-1]
        print(tca)

main()
